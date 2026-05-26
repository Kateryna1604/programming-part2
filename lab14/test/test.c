#include "../src/lib.h"
#include <assert.h>
#include <string.h>

int main() {
    Mail m;

    strcpy(m.subject, "Test");
    strcpy(m.body, "Hello world");

    int size = calculateSize(&m);

    assert(size > 0);

    return 0;
}
