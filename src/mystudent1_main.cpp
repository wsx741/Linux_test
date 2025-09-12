#include "mystudent1.h"

int main()
{
    //Student *wangwu = new Student("王五", 21, 0);
    //delete wangwu;
    Student zhangsan("张三","324353",18,0);
    /*
    zhangsan.setName("张三");
    zhangsan.setId("2314324");
    zhangsan.setAge(18);
    */
    zhangsan.disp();
    Student lisi("李四", 20, 1);
    lisi.disp();
    Student wangwu = lisi;
    wangwu.setName("王五");
    wangwu.disp();
    return 0;
}








