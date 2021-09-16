#include <vector>
#include <algorithm>
#include <math.h>
#include <chrono>
#include <iostream>
#include <iomanip>
using namespace std;

const float M_PI_F = 3.14159265358F;


double fun1(int upsampleRow, vector<float>& vec)
{
    const float m_Q = 0.5F;
    vec.resize(upsampleRow);
    float* pVec = vec.data();

    float step = 2.0F / (upsampleRow - 1.0F);

    const auto begin= std::chrono::system_clock::now();
    for (int i = 0; i != upsampleRow; ++i)
    {
        float q = std::abs(i * step - 1.0F);
        float temp = cosf(0.5F * M_PI_F * (q - m_Q) / (1.0F - m_Q));
        pVec[i] = q < m_Q ? 1.0F : temp * temp;
    }

    const auto end = std::chrono::system_clock::now() - begin;
  
    std::cout << std::left << std::setw(30) << "\tArithmetic in Loop: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
    return std::chrono::duration<double>(end).count();
}

double fun2(int upsampleRow, vector<float>& vec)
{
    const float m_Q = 0.5F;
    vec.resize(upsampleRow);
    float* pVec = vec.data();

    float step = 2.0F / (upsampleRow - 1.0F);
    
    const auto begin= std::chrono::system_clock::now();
    
    float coef = 0.5F * M_PI_F / (1.0F - m_Q);
    for (int i = 0; i != upsampleRow; ++i)
    {
        float q = std::abs(i * step - 1.0F);
        float temp = cosf(coef * (q - m_Q));
        pVec[i] = q < m_Q ? 1.0F : temp * temp;
    }

    const auto end = std::chrono::system_clock::now() - begin;
  
    std::cout << std::left << std::setw(30) << "\tPre-Calculated: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
    return std::chrono::duration<double>(end).count();
}


double func3(int upsampleRow, vector<float>& vec){

    float m_Q = 0.5F;
    float step = 2.0F / (upsampleRow - 1.0F);

    int index = 0;
    vec.resize(upsampleRow);
    float* pVec = vec.data();


    const auto begin= std::chrono::system_clock::now();
    for (float q = -1.0F; q <= 1.0F; q += step)
    {
        float temp = std::cosf(0.5F*M_PI_F*(std::fabsf(q) - m_Q) / (1.0F - m_Q));
        pVec[index++] = fabs(q) < m_Q ? 1.0F : temp*temp;
    }

    const auto end = std::chrono::system_clock::now() - begin;
    std::cout << std::left << std::setw(30) << "\tLegacy: " << std::right << std::setw(10) << std::chrono::duration<double>(end).count() << " sec" << std::endl;
    return std::chrono::duration<double>(end).count();
}

void perfTest1(){
    int upsampleRow = 1024;

    vector<float> vec1;
    double t1 = fun1(upsampleRow, vec1);

    vector<float> vec2;
    double t2 = fun2(upsampleRow, vec2);
    
    if(vec1.size() != vec2.size()){
        cerr << "Correctness not math at size" << endl;
        return;
    }

    for(int i = 0; i < vec1.size(); ++i){
        if(vec1[i] - vec2[i] > 1E-6F){
            cerr << "Correctness not math at i = " << i << endl;
            return;
        }
    }

    cout << "All Result are the same" << endl;
    cout << "pre-calculated is " << 100 * (t1 - t2) / t1 << "% faster" << endl;

}

void CorrectnessTest(){

    try{
        int upsampleRow = 1024 * 250000;
    
        vector<float> vec1;
        double t1 = fun1(upsampleRow, vec1);


        vector<float> vec3;
        double t3 = fun2(upsampleRow, vec3);

        if(vec1.size() != vec3.size()){
            cout << "Correctness not math at size" << endl;
            return;
        }

        for(int i = 0; i < vec1.size(); ++i){
            if(vec1[i] - vec3[i] > 1E-6F){
                cout << "Correctness not math at i = " << i << endl;
                return;
            }
        }


        cout << "All Result are the same" << endl;
        cout << "Legacy is " << 100 * (t1 - t3) / t1 << "% faster" << endl;

    }catch(exception& ex){
        cout << "Exception: = " << ex.what() << endl;  
        return;
    }
    

}

int main(){
    
    perfTest1();
    //CorrectnessTest();
}