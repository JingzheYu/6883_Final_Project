

#include "Group.hpp"
#include "OpeOverLoading.hpp"
#include <cstdlib>

void Group::CalAvgCAAR(){
    vector<double> CAAR(120);
    AvgCAAR.resize(120);
    AvgAAR.resize(120);
    //Run sampling for 30 times
    for(int i = 1; i <= 30; i++)
    {
        vector<double> aar = AAR();
        CAAR [0] = aar[0];
        for(int i=1; i<120; i++)
            CAAR[i] = CAAR[i-1] + aar[i];
        // Update data member AvgAAR
        AvgAAR = ((i-1.0)/i) * AvgAAR + (1.0/i) * aar;
        // Update data member AvgCAAR
        AvgCAAR = ((i-1.0)/i) * AvgCAAR + (1.0/i) * CAAR;
    }
}

vector<double> Group::AAR(){
    vector<double> result(120);
    // Use index to randomly select 30 stocks
    for(int i = 1;i<=30;i++){
        double U = (rand()+1.0)/(RAND_MAX+1.0);
        int index = U*num;
        result =  ((i-1.0)/i)*result + (1.0/i)*MyStock[tickerlist[index]].GetAR();
                
    }
    return result;
}
