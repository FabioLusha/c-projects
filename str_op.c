/* my_str_cat: concatenate t to end of s; s must be big enough */
void my_strcat(char *s, char *t){

	while( *s++ != '\0')
		;
	s--;
	while( *s++ = *t++)
		;
}

/* my_strend: return 1 if string t occurs at the end of string s */
int my_strend(char *s, char *t){
	char *p = t;

	while( *s++ != '\0')
		;
	while( *t++ != '\0')
		;

	s--; t--;
	for( ; *s == *t && p <= t; s--, t--)
		;

	if( t < p)
		return 1;
	else
		return 0;
}
/* my_strcpy: copies t on s */
void my_strcpy(char *s, char *t){
	while( *s++ = *t++) /* '\0 = 0, so false when the end of lines comes  */
		;
}
/* my_strncpy: copies at most the first n characters of t on s */
void my_strncpy(char *s, char *t, int n){

	char *p = t;
	while( t < p + n && (*s++ = *t++) != '\0') 
		;
}

/* my_strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int my_strncmp(char *s, char *t){
	for(; *s == *t; s++, t++)
		if( *s = '\0' )
			return 0;
	return *s - *t;
}

/* my_strncmp: compares the first n elements of the strings, returns a negatvie, 0, positive value if s is lesser, equal or greater than t in a lexiographic order */
int my_strncmp(char *s, char *t, int n){
	
	char *p = s;
	for( ; s - p <= n && *s == *t; s++, t++)
		if(*s == '\0')
			return 0;

	return *s - *t;
}
