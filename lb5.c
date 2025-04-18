#include <stdio.h>
#include <string.h>

struct A{
	char buffer[8];
};

struct B{
	int secret;
};

struct AB{
	struct A a;
	struct B b;
};

int main(){
	struct AB ab;

	ab.b.secret = 123456;

	printf("Before overflow: b.secret = %d\n", ab.b.secret);

	strcpy(ab.a.buffer ,"AAAAAAAAAAAA");

	printf("After overflow: b.secret = %d\n", ab.b.secret);
	
	return 0;
}
