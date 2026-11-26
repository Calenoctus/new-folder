git#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256
#define NAME_SIZE 20
#define SCORE_SIZE 32

static char *trim(char *text)
{
	while (isspace((unsigned char)*text)) {
		text++;
	}

	char *end = text + strlen(text);
	while (end > text && isspace((unsigned char)end[-1])) {
		*--end = '\0';
	}
	return text;
}

static int parse_score(const char *text, int *score)
{
	char *end;
	errno = 0;
	long value = strtol(text, &end, 10);

	if (text == end || errno == ERANGE || value < INT_MIN || value > INT_MAX) {
		return 0;
	}
	while (isspace((unsigned char)*end)) {
		end++;
	}
	if (*end != '\0') {
		return 0;
	}

	*score = (int)value;
	return 1;
}

int main(void)
{
	FILE *file = fopen("students.csv", "r");
	if (file == NULL) {
		fprintf(stderr, "Error: Could not open students.csv!\n");
		return 1;
	}

	char line[LINE_SIZE];
	unsigned long lineNumber = 0;
	printf("--- Processing Student Records ---\n");

	while (fgets(line, sizeof(line), file) != NULL) {
		lineNumber++;

		/* Discard and report a line that did not fit in the input buffer. */
		if (strchr(line, '\n') == NULL && !feof(file)) {
			int ch;
			while ((ch = fgetc(file)) != '\n' && ch != EOF) {
				/* Consume the remainder of this overlong line. */
			}
			fprintf(stderr, "WARNING: Skipping overlong line %lu.\n", lineNumber);
			continue;
		}

		line[strcspn(line, "\r\n")] = '\0';

		char *fields[4];
		fields[0] = line;
		int fieldCount = 1;
		for (char *p = line; *p != '\0'; p++) {
			if (*p == ',') {
				if (fieldCount == 4) {
					fieldCount++;
					break;
				}
				*p = '\0';
				fields[fieldCount++] = p + 1;
			}
		}

		if (fieldCount != 4) {
			fprintf(stderr, "WARNING: Skipping malformed line %lu (expected 4 fields).\n",
					lineNumber);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			fields[i] = trim(fields[i]);
		}

		if (fields[0][0] == '\0' || strlen(fields[0]) >= NAME_SIZE) {
			fprintf(stderr, "WARNING: Skipping malformed line %lu (invalid name).\n",
					lineNumber);
			continue;
		}

		int scores[3];
		if (!parse_score(fields[1], &scores[0]) ||
			!parse_score(fields[2], &scores[1]) ||
			!parse_score(fields[3], &scores[2])) {
			fprintf(stderr, "WARNING: Skipping malformed record for %s (invalid score data).\n",
					fields[0]);
			continue;
		}

		double average = (scores[0] + (double)scores[1] + scores[2]) / 3.0;
		printf("%s -> Average: %.2f\n", fields[0], average);
	}

	if (ferror(file)) {
		fprintf(stderr, "Error: Failed while reading students.csv.\n");
		fclose(file);
		return 1;
	}

	fclose(file);
	printf("\n--- Processing Complete ---\n");
	return 0;
}
