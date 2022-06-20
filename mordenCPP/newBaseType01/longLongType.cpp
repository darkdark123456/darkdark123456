#include <iostream>
#include <limits>

/* c style progamming */


int test(){
    long long value=65536LL;/*2^16==1000 0000 0000 0000*/
    std::cout<<"value "<<value<<std::endl;  // 65536
    long long newValue=value<<16;
    std::cout<<"newValue "<<newValue<<std::endl; // 4294967296
    return 1;
    // 假设计算机为64bit ，则有(x个0) 1000 0000 0000 0000 0000 0000 0000 0000

}



int test2(){

    /*位域操作*/
    struct longLongStruct{
        long long x1:8;
        long long x2:56;
        long long x3:64;
    } longLongObject;
    longLongObject.x1=8;
 //  longLongObject.x1=65536; // error  overflow
    std::cout<<longLongObject.x1<<std::endl;

    /*long long 用于枚举类型*/
    enum longLongEnum : long long {
        number1=8,
        number2
    } longLongEnumObject;

    longLongEnumObject=longLongEnum::number2;
    std::cout<<"longLongEnumObject  "<<longLongEnumObject;
    return 1;
}


int test3(){
    std::cout<<"NumbetLimitMax "<<std::numeric_limits<long long>::max()<<std::endl;
    std::cout<<"NumbetLimitMin "<<std::numeric_limits<long long>::min()<<std::endl;
    std::cout<<"uNumbetLimitMax "<<std::numeric_limits<unsigned long long>::max()<<std::endl;
    std::cout<<"uNumbetLimitMin "<<std::numeric_limits<unsigned long long>::min()<<std::endl;
    return 1;

}


int test4(){
   //char utf8c=u8'x'; // c++11 error
   char16_t utf16c=u'好';
   char32_t utf32c=U'你';
   char utf8[]=u8"你好世界";
   char16_t utf16[]=u"你好世界";
   char32_t utf32[]=U"你好世界";

   //std::cout<<"utf8c "<<utf8c<<std::endl;
   std::cout<<"utf16c "<<utf16c<<std::endl;
   std::cout<<"utf32c "<<utf32c<<std::endl;

   std::cout<<"utf8[] "<<utf8<<std::endl;
   return 1;
}

int main(){
    test4();
    return 1;
}
