# malloc和free函数的具体作用

在c 语言中要动态的释放内存，就必然要使用指针，将动态分配获得的空间地址赋值给指针。

c语言中动态分配内存的函数为malloc()，在用完后，要及时调用free()函数释放。

free函数仅仅是告诉系统这块空间不用了，操作系统回收空间。而指向这块空间的指针并没有改变，他的值依然指向这块空间。

所以在调用free函数后，将指针也赋值为NULL，在使用指针前检查指针是否为空，因此可以避免野指针所带来的危险

如：

```c
#include <stdio.h>

void main () {
    int *a = (int *)malloc(sizeof(int));
    printf("a = %d\n", a);
    free(a);
    pritnf("a = %d\n", a);
}
```



