#include <stdio.h>
#include <name_string.h>

int main(int argc, char **argv)
{
    string *test = create_from_cstr("Testing");
    printf("String: %s\n", test->c_str);
    printf("Size expected: %d\n", 7);
    printf("Actual Size: %d\n", test->len);

    string *other = create_from_cstr("This is also a test");
    string *combined = concatenate_string(test, other);
    printf("First String: %s\n", test->c_str);
    printf("Second String: %s\n", other->c_str);
    printf("Expected: TestingThis is also a test\n");
    printf("Actual: %s\n", combined->c_str);
    printf("Length of first string: %d\n", test->len);
    printf("Length of second string: %d\n", other->len);
    printf("Expected Length: %d\n", test->len + other->len);
    printf("Length of Combined String: %d\n", combined->len);

    return 0;
}
