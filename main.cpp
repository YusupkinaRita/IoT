#include <iostream>
#include <random>


class pattern{
private:
    double _value;

public:
    pattern()=delete;
    pattern( double min, double max){
        if(static_cast<int>(max)!=0)
        _value=min+rand()%static_cast<int>(max);

    }
    void update( double min,  double max){
        double del = -10 + rand() % 20;
        _value += del / 10;
        if (_value > max)
            _value = max;
        else if (_value < min)
            _value = min;
    }
    double operator()(){
            return _value;
        }

};

class temp_sens:public pattern{
private:
public:
    const double MIN= -50;
    const double MAX= 100;
    temp_sens():pattern(MIN, MAX){}
    void temp_update(){
        update(MIN,MAX);
    }
};
class hum_sens:public pattern{
private:
public:
    const double MIN = 0;
    const double MAX = 100;
    hum_sens():pattern(MIN, MAX){}
    void hum_update(){
        update(MIN,MAX);
    }

};
class pressure_sens:public pattern{
private:
public:
    const double MIN = 600;
    const double MAX = 900;
    pressure_sens():pattern(MIN, MAX){}
    void pressure_update(){
        update(MIN,MAX);
    }



};
class co2_sens:public pattern{
private:
public:
    const double MIN = 0;
    const double MAX = 100;
    co2_sens():pattern(MIN, MAX){}
    void co2_update(){
        update(MIN,MAX);
    }

};

class ATH{
private:
    temp_sens _temp;
    hum_sens _hum;

public:

double GetTemp(){
    return _temp();
}

double GetHum(){
    return _hum();
}

std::tuple<double, double> operator()(){
    return std::tuple<double, double>(_temp(), _hum());
}
};




int main(){
    srand(time(NULL));
    temp_sens a=temp_sens();
    std::cout<<a()<<std::endl;
    a.temp_update();
    std::cout<<a()<<std::endl;





    return 0;
}