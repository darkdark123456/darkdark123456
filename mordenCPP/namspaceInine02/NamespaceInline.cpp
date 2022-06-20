#include <iostream>

namespace S1{
    void ff(){
        std::cout<<"namespace S1"<<std::endl;
    }
}

namespace S2{
    void ff(){
        std::cout<<"namespace S2"<<std::endl;
    }
}

namespace S3{
    void ff(){
        std::cout<<"namespace S3"<<std::endl;
    }
}

using namespace S1;



namespace Parent{
    namespace Child01{
        void ff(){
            std::cout<<"Child01 namespace "<<std::endl;
        }
    }
    inline namespace Child02{
        void ff(){
            std::cout<<"Child02 namespace "<<std::endl;
        }
    }
}


/*老的接口和新的接口并存，有的用户不愿意用新接口那就调用之前的老接口即可*/
namespace App{
    namespace Version01{
        void ff(){
            std::cout<<"old inerface "<<std::endl;
        }
    }

    inline namespace Version02{
        void ff(){
            std::cout<<"new  inerface "<<std::endl;
        }
    }
}



/*屎山代码*/
namespace Name01{
    namespace Name02{
        namespace Name03{
            void ff(){
                std::cout<<"Name03 namespace"<<std::endl;
            }
        }
    }
}


/*对上面的优化 一种等价写法*/
namespace Name001::Name002::Name003{
    void ff(){
        std::cout<<"Name03 namespace"<<std::endl;
    }
}


int test(){
    ff();
    S2::ff();
    S3::ff();
    return 1;}


int test2(){
    Parent::Child01::ff();
    Parent::ff();
    return 1;
}


int test3(){
    App::Version01::ff();
    App::ff();
    return 1;
}


int test4(){
    Name01::Name02::Name03::ff();
    Name001::Name002::Name003::ff();
    return 1;
}




int main(){
    test4();
    return 1;
}
