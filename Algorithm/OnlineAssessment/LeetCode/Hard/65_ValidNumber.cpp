/*
DFA or State Machine

*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    
public:

    enum MOVE {
        DIGIT,
        DOT,
        SIGN,
        EXP,
        NONE
    };
    
    
    enum STAGE {
        START,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN
    };
    
    
public:
    bool isNumber(string s) {
        
        unordered_map<STAGE, unordered_map<MOVE, STAGE>> states;
        unordered_set<STAGE> finalStates;
        
        InitStateMachine(states, finalStates);
        
        STAGE current = STAGE::START;
        MOVE move = MOVE::NONE;
        
        
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            
            if(isdigit(c)){
                move = MOVE::DIGIT;
            }else if(c == '+' || c == '-'){
                move = MOVE::SIGN;
            }else if(c == 'e' || c == 'E'){
                move = MOVE::EXP;
            }else if(c == '.'){
                move = MOVE::DOT;
            }else{
                return false;
            }
            
            if(states[current].find(move) == states[current].end()){
                return false; // this state doesn't have next corresponding move
            }
            
            current = states[current][move];
            
        }
        
        return finalStates.find(current) != finalStates.end();
        
    }
    
    void InitStateMachine(unordered_map<STAGE, unordered_map<MOVE, STAGE>>& states, unordered_set<STAGE>& finalState){
        // start -> 1, 2, 3
        unordered_map<MOVE, STAGE> StartStage;
        StartStage[MOVE::DIGIT] = STAGE::ONE;
        StartStage[MOVE::SIGN] = STAGE::TWO;
        StartStage[MOVE::DOT] = STAGE::THREE;
        
        states[STAGE::START] = StartStage;
        
        // Stage One
        unordered_map<MOVE, STAGE> OneState;
        OneState[MOVE::DIGIT] = STAGE::ONE;
        OneState[MOVE::DOT] = STAGE::FOUR;
        OneState[MOVE::EXP] = STAGE::FIVE;
        
        states[STAGE::ONE] = OneState;
        finalState.insert(STAGE::ONE);
        
        // STAGE two
        unordered_map<MOVE, STAGE> TwoState;
        TwoState[MOVE::DIGIT] = STAGE::ONE;
        TwoState[MOVE::DOT] = STAGE::THREE;
        
        states[STAGE::TWO] = TwoState;
        
        // STAGE three
        unordered_map<MOVE, STAGE> threeState;
        threeState[MOVE::DIGIT] = STAGE::FOUR;
        
        states[STAGE::THREE] = threeState;
        
        // STAGE 4
        unordered_map<MOVE, STAGE> FourState;
        FourState[MOVE::DIGIT] = STAGE::FOUR;
        FourState[MOVE::EXP] = STAGE::FIVE;
        
        states[STAGE::FOUR] = FourState;
        finalState.insert(STAGE::FOUR);
        
        // STAGE 5
        unordered_map<MOVE, STAGE> fiveState;
        fiveState[MOVE::SIGN] = STAGE::SIX;
        fiveState[MOVE::DIGIT] = STAGE::SEVEN;
        
        states[STAGE::FIVE] = fiveState;

        // STAGE 6
        unordered_map<MOVE, STAGE> sixState;
        sixState[MOVE::DIGIT] = STAGE::SEVEN;
        
        states[STAGE::SIX] = sixState;
        
        // STAGE 7
        unordered_map<MOVE, STAGE> sevenState;
        sevenState[MOVE::DIGIT] = STAGE::SEVEN;
        
        states[STAGE::SEVEN] = sevenState;   
        finalState.insert(STAGE::SEVEN);
        
    }
    
};