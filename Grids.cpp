//
// Created by 研究用 on 2017/08/24.
//

#include "Grids.h"
#include "parameters.h"

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

Grids::Grids() {
    //install grids
    cout<<"Choose the grids (0-2)"<<endl;
    int input;
    cin>>input;
    int tate,yoko;
    if(input==0){
        tate=2;
        yoko=3;
        grids.resize(tate);
        for(int i=0;i<tate;i++) grids[i].resize(yoko);
        grids[0][0]=0; grids[0][1]=0; grids[0][2]=0;
        grids[1][0]=0; grids[1][1]=0; grids[1][2]=0;
    }
    else if(input==1){
        tate=2;
        yoko=3;
        grids.resize(tate);
        for(int i=0;i<tate;i++) grids[i].resize(yoko);
        grids[0][0]=0; grids[0][1]=1; grids[0][2]=0;
        grids[1][0]=0; grids[1][1]=0; grids[1][2]=0;
    }
    else if(input==2){
        tate=4;
        yoko=4;
        grids.resize(tate);
        for(int i=0;i<tate;i++) grids[i].resize(yoko);
        grids[0][0]=0; grids[0][1]=0; grids[0][2]=0; grids[0][3]=0;
        grids[1][0]=0; grids[1][1]=0; grids[1][2]=0; grids[1][3]=0;
        grids[2][0]=0; grids[2][1]=0; grids[2][2]=0; grids[2][3]=0;
        grids[3][0]=0; grids[3][1]=1; grids[3][2]=1; grids[3][3]=0;
    }

    goal.setIJ(0,yoko-1);

    //initialize value table
    value_table.resize(tate);
    for(int i=0;i<tate;i++) value_table[i].resize(yoko);
    for(int i=0;i<tate;i++){
        for(int j=0;j<yoko;j++) value_table[i][j]=1000; //initial value
    }
    value_table[goal.getI()][goal.getJ()]=0;    //value at goal

    //initialize policy table
    policy_table.resize(tate);
    for(int i=0;i<tate;i++) {
        policy_table[i].resize(yoko);
        for(int j=0;j<yoko;j++){
            if(i==goal.getI() && j==goal.getJ()) policy_table[i][j]='*';
        }
    }

}

void Grids::evaluate_value_table() {
    vector<vector<double> > temp_value_table;
    while(temp_value_table!=value_table){
        temp_value_table=value_table;
        for(int i=0;i<grids.size();i++){
            for(int j=0;j<grids[i].size();j++){
                evaluate_value(i,j);
            }
        }
    }
}

void Grids::evaluate_value(int i_input, int j_input) {
    if(grids[i_input][j_input]==1) return;

    int i_next,j_next,i_side,j_side,i_side2,j_side2;
    int direction;
    double temp;
    double value_next,value_side,value_side2;
    for(direction=0;direction<4;direction++) {
        if(direction==0){
            i_next=i_input-1;
            j_next=j_input;
            i_side=i_input;
            j_side=j_input-1;
            i_side2=i_input;
            j_side2=j_input+1;
        }
        else if(direction==1){
            i_next=i_input;
            j_next=j_input-1;
            i_side=i_input-1;
            j_side=j_input;
            i_side2=i_input+1;
            j_side2=j_input;
        }
        else if(direction==2){
            i_next=i_input+1;
            j_next=j_input;
            i_side=i_input;
            j_side=j_input-1;
            i_side2=i_input;
            j_side2=j_input+1;
        }
        else if(direction==3){
            i_next=i_input;
            j_next=j_input+1;
            i_side=i_input-1;
            j_side=j_input;
            i_side2=i_input+1;
            j_side2=j_input;
        }

        if(0<=i_next && i_next<grids.size() && 0<=j_next && j_next<grids[0].size()){
            if(grids[i_next][j_next]==0) value_next=value_table[i_next][j_next];
            else value_next=collision_cost;
        }
        else value_next=collision_cost;
        if(0<=i_side && i_side<grids.size() && 0<=j_side && j_side<grids[0].size()) {
            if(grids[i_side][j_side]==0) value_side=value_table[i_side][j_side];
            else value_side=collision_cost;
        }
        else value_side=collision_cost;
        if(0<=i_side2 && i_side2<grids.size() && 0<=j_side2 && j_side2<grids[0].size()) {
            if(grids[i_side2][j_side2]==0) value_side2=value_table[i_side2][j_side2];
            else value_side2=collision_cost;
        }
        else value_side2=collision_cost;

        temp=cost_step+success_prob*value_next
                +(1.0-success_prob)*(value_side+value_side2)/2.0;

        if(temp<value_table[i_input][j_input]){
            value_table[i_input][j_input]=temp;
            if(direction==0) policy_table[i_input][j_input]='^';
            else if(direction==1) policy_table[i_input][j_input]='<';
            else if(direction==2) policy_table[i_input][j_input]='v';
            else if(direction==3) policy_table[i_input][j_input]='>';
        }
    }
}

void Grids::show_grids() {
    cout<<"Show grids"<<endl;
    for(int i=0;i<grids.size();i++){
        for(int j=0;j<grids[0].size();j++) cout<<grids[i][j]<<" ";
        cout<<endl;
    }
}

void Grids::show_value_table() {
    cout<<"Show value table"<<endl;
    for(int i=0;i<grids.size();i++){
        for(int j=0;j<grids[0].size();j++) cout<<value_table[i][j]<<" ";
        cout<<endl;
    }
}

void Grids::show_policy_table() {
    cout<<"Show policy table"<<endl;
    for(int i=0;i<grids.size();i++){
        for(int j=0;j<grids[0].size();j++) cout<<policy_table[i][j]<<" ";
        cout<<endl;
    }
}


