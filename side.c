#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 30

void memprint(char *, char *, int);
void part0(void);
int part1(void);
void part2(int);
void part3();
void part4();
void part5(char *);
void part6();

int main(int argc, char *argv[]) {
	int len;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	part0();
	len = part1();
	part2(len);
	part3();
	part4();
	part5(argv[1]);
	part6();
}

void memprint(char *s, char *fmt, int len) {
	
	int i;
	char fmt_with_space[8];

	sprintf(fmt_with_space, "%s ", fmt);
	for (i = 0; i < len; i++) {
		printf(fmt_with_space, s[i]);
	}
	printf("\n");
}


void part0() {
	printf("===== Intro =====\n");
	char s1[] = { 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x0a };
	char s2[] = { 0xe5, 0x8f, 0xb0, 0xe7, 0x81, 0xa3, 0x0a };
	char s3[] = { 0xf0, 0x9f, 0x98, 0x82, 0x0a };

	write(STDOUT_FILENO, s1, 6);
	write(STDOUT_FILENO, s2, 7);
	write(STDOUT_FILENO, s3, 5);
}

int part1() {
	
	char s1[] = "hello";
	char s2[10];

    int s1_len = sizeof(s1);
    int s2_len = sizeof(s2);

    printf("===== Question 1 =====\n");
    printf("Size of s1 without assigning: %ld\n", sizeof(s1));
    printf("s1 printed is %s\n", s1);

	printf("===== Question 2 =====\n");
    printf("Size of S2: %d bytes\n", s2_len);
    printf("Size of s2 without assigning: %ld\n", sizeof(s2));

	printf("===== Question 3 =====\n");

    memprint(s1, "%02x", sizeof (s1_len));
    memprint(s1, "%d", sizeof (s1_len));
    memprint(s1, "%c", sizeof (s1_len));

	return s1_len;
}

void part2(int len) {
	char s1[] = "hello";
	char s2[1024];
	char *s3 = s1;

	
	memcpy(s2, s1, len);

	printf("===== Question 4 =====\n");
    printf("The address is %lu\n", (long unsigned int) &s1);
    printf("The address is %lu\n", (long unsigned int) &s2);
    printf("The address is %lu\n", (long unsigned int) &s3);

	printf("===== Question 5 =====\n");
    printf("The address of s1 is %lu\n", (long unsigned int) s1);
    printf("The address pf s2 is %lu\n", (long unsigned int) s2);
    printf("The address of s3 is %lu\n", (long unsigned int) s3);

	printf("===== Question 6 =====\n");
    printf("The content of s1 is %s\n", s1);
    printf("The content of s2 is %s\n", s2);
    printf("The content of s3 is %s\n", s3);

	printf("===== Question 7 =====\n");
    printf("%d\n", s1==s2);
    printf("%d\n", s1==s3);
    printf("%d\n", s2==s3);

	printf("===== Question 8 =====\n");
    printf("Comparison between s1 and s2 %d\n", strcmp(s1, s2));
    printf("Comparison between s1 and s3 %d\n", strcmp(s1, s3));
    printf("Comparison between s2 and s3 %d\n", strcmp(s2, s3));

	s1[1] = 'a';
	printf("===== Question 9 =====\n");
    printf("The content of s1 here is %s\n", s1);

    printf("===== Question 10 =====\n");
    printf("%d\n", s1==s2);
    printf("%d\n", s1==s3);
    printf("%d\n", s2==s3);

	printf("===== Question 11 =====\n");
    printf("Comparison between s1 and s2 %d\n", strcmp(s1, s2));
    printf("Comparison between s1 and s3 %d\n", strcmp(s1, s3));
    printf("Comparison between s2 and s3 %d\n", strcmp(s2, s3));
}

void part3() {
	char s1[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	char s2[] = { 97, 98, 99, 100, 101, 102 };
	char s3[] = { 0x61, 0x62, 0x63, 0x64, 0x65, 0x66 };

	printf("===== Question 12 =====\n");
    printf("Comparison between s1 and s2 %d\n", memcmp(s1, s2, 5));
    printf("Comparison between s1 and s3 %d\n", memcmp(s1, s3, 5));
    printf("Comparison between s2 and s3 %d\n", memcmp(s2, s3,5));
}

void part4() {
	char s1[] = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0' };
	char s2[] = { 'a', 'b', 'c', '\0', 'x', 'y', 'z', '\0' };
	char s3[8];
	char s4[8];
	int myval = 42;

	printf("===== Question 13 =====\n");
    printf("Comparison between s1 and s2 %d\n", memcmp(s1, s2, 7));

	printf("===== Question 14 =====\n");
    printf("Comparison between s1 and s2 %d\n", strcmp(s1, s2));


	printf("===== Question 15 =====\n");
    memset(s3, 'z', sizeof(s3));
    memset(s4, 'z', sizeof(s4));
    memprint(s3, "%02x",sizeof (s3));
    memprint(s4, "%02x",sizeof (s4));

	printf("===== Question 16 =====\n");
    strcpy(s3, s1);
    memprint(s3,"%02x",sizeof (s3));

	printf("===== Question 17 =====\n");
    sprintf(s4 ,"%s %d\n", s1, myval);
    memprint(s4, "%02x", sizeof(s4));
    
}

void part5(char *filename) {
	char buf[BUFSIZE];
	size_t nread, totread;
	int fd1, fd2;
	int i;
	int ret;
	FILE *f;

	printf("===== Question 18 =====\n");
    int din = fileno(stdin);
    int out = fileno(stdout);
    int err = fileno(stderr);
    printf("Value of stdin %d\n", din);
    printf("Value of stdout %d\n", out);
    printf("Value of stderr %d\n", err);

	printf("===== Question 19 =====\n");
    memset(buf, 0x7a, BUFSIZE);
    buf[24] = 0;
    memprint(buf, "%02x", sizeof(buf));

	printf("===== Question 20 =====\n");
    printf("Content of buf %s\n", buf);
    printf("Content of buf using write()");
    printf("\n");
    write(STDOUT_FILENO, buf, BUFSIZE);
    printf("\n");
    

	printf("===== Question 21 =====\n");
    fprintf(stderr, "%s", buf);
    printf("\n");
    write(STDERR_FILENO, buf, BUFSIZE);
    printf("\n");

	printf("===== Question 22 =====\n");\
    fd1 = open("test.txt", O_RDONLY);
    fd2 = fd1;
    printf("This is fd1 %d\n", fd1);
    printf("This is fd2 %d\n", fd2);
    

	nread = 0;
	totread = 0;
	printf("===== Question 23 =====\n");
    nread = read(fd1, buf, 4);
    totread = nread;
    printf("Content of nread: %zu\n", nread);
    printf("Content of totread %zu\n", totread );
    memprint(buf, "%02x", BUFSIZE);
    

    printf("===== Question 24 =====\n");
    nread = read(fd2, &buf[totread], 4);
    totread = nread;
    printf("Content of nread: %02x\n", nread);
    printf("Content of totread %02x\n",totread );
    memprint(buf, "%02x", BUFSIZE);
    
    
    
    

	printf("===== Question 25 =====\n");
    nread = read(fd2, &buf[totread], 50);
    totread = nread;
    printf("Content of nread: %02x\n", nread);
    printf("Content of totread %02x\n",totread );
    memprint(buf, "%02x", BUFSIZE);
    
    
    

	printf("===== Question 26 =====\n");
    nread = read(fd2, buf + totread, 50);
    totread =  nread;
    printf("Content of nread: %02x\n", nread);
    printf("Content of totread %02x\n",totread );
    memprint(buf, "%02x", BUFSIZE);


	printf("===== Question 27 =====\n");
    FILE *fp;
    fp = fopen("test.txt", "r");
    int fd = fileno(fp);
    printf("File: %d\n", fd);
    fclose(fp);
    

	printf("===== Question 28 =====\n");
    printf("Final value: %d\n", close(fd1));
    printf("Final value: %d\n", close(fd2));
    


}

void part6() {
	char *s1;

	printf("===== Question 29 =====\n");

}
