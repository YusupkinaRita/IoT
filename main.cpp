#include <iostream>
#include <random>
#include <tuple>


class pattern{
private:
    double _value;
    int _min;
    int _max;
public:
    pattern()=delete;
    pattern( double min, double max){
    
        _value=min+rand()%static_cast<int>(max);
        _min=min;
        _max=max;

    }
    void update(){
        double del = -10 + rand() % 20;
        _value += del / 10;
        if (_value > _max)
            _value = _max;
        else if (_value < _min)
            _value = _min;
    }
        void print(){
            std::cout<<_value<<std::endl;
        }

};

class temp_sens:public pattern{
private:
public:
    static const int MIN= -50;
    static const int MAX= 100;
    temp_sens():pattern(MIN, MAX){}
    
};
class hum_sens:public pattern{
private:
public:
    static const int  MIN = 0;
    static const int  MAX = 100;
    hum_sens():pattern(MIN, MAX){}
    

};
class pressure_sens:public pattern{
private:
public:
    static const int  MIN = 600;
    static const int  MAX = 900;
    pressure_sens():pattern(MIN, MAX){}
    



};
class co2_sens:public pattern{
private:
public:
    static const int  MIN = 0;
    static const int  MAX = 100;//статичные поля существуют и до создания класса
    co2_sens():pattern(MIN, MAX){}
    

};

class ATH:public temp_sens, public hum_sens{
private:
public:
void print_temp(){
    temp_sens::print();
    }

void hum_temp(){
    hum_sens::print();
    }

};

class sensors_handler{
private:
pattern** _array;
size_t _size;
size_t _count;
public:
sensors_handler(size_t size){
    _size=size;
    _array=new pattern*[_size];
    _count=0;
    
}

void append_sensor(pattern* x){
    if(_count<_size){
    _array[_count]=x;
    _count++;
    }
}

void print_sensor(size_t ind){
    _array[ind]->print();

}
void print_sensor(){
    for(size_t i=0;i<_size;i++){
    _array[i]->print();
    }

}



};




int main(){
    srand(time(NULL));
    temp_sens temp=temp_sens();
    temp.print();
    hum_sens hum;
    pressure_sens pressure;
    co2_sens co2;
    ATH ath;

    sensors_handler sensors=sensors_handler(5);
    sensors.append_sensor(&temp);

    sensors.print_sensor(0);   





    return 0;
}