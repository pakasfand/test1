
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "Header.h"

// We be making em changes in here, lets see how it be
void main()
{
	FILE* testfile;
	const char testfileContent[255];

	testfile = fopen("file.txt", "r");
	fgets(testfileContent, sizeof(testfileContent), testfile);


	char endChar = ';';
	char ScopeID[64];
	char DeviceID[64];
	char SharedAccessKey[64];

	char const* tempbuf;

	tempbuf = string_copy(testfileContent, endChar, ScopeID, sizeof(ScopeID));

	tempbuf = string_copy(tempbuf, endChar, DeviceID, sizeof(DeviceID));

	tempbuf = string_copy(tempbuf, endChar, SharedAccessKey, sizeof(SharedAccessKey));
	fprintf(stdout, "%s\n%s\n%s\n", ScopeID, DeviceID, SharedAccessKey);



	Sleep(2000);

}

static char const* string_copy( char const* source, char endChar, char* dest, size_t len) {


	size_t index = 0;
	while (index < len) {

		//Grab a character from the string pointed by source
		char currentChar = *source++;

		if (currentChar == endChar) {
			*dest = 0;
			return source;
		}

		*dest = currentChar;

		dest++;
		index++;
	}


	return NULL;
}























static char const* copy(const char* src, char c, char* dst, size_t len)
{
	size_t index = 0;
	while (index < len) {
		// Get Character
		char ch = *src++;

		// Check for end character
		if (ch == c) {
			*dst = 0;
			return src;
		}

		// Check for EOF
		if (ch == 0) {
			*dst = 0;
			return NULL;
		}

		*dst++ = ch;
		index++;
	}

	// Buffer Overflow
	return NULL;
}



static int string_parse(char const* data, char const* key, char* val, size_t len)
{
	// Raw Copy
	if (key == NULL) {
		snprintf(val, len, data);
		return 0;
	}

	// String Pointer
	char const* str = data;
	if (str == NULL) return 0;

	// Find Key
	char name[64];
	while (str) {
		// Get Key Name
		str = copy(str, '=', name, sizeof(name));
		if (str == NULL) return 0;

		// Get Key Value
		str = copy(str, ';', val, len);

		// Compare Keys
		if (strcmp(key, name) == 0) {
			return 1;
		}
	}

	return 0;
}

