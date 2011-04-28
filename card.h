#ifndef CARD_H
#define CARD_H

class Card{
      public:
             Card(int cost, int value, int victory);
      private:
             int m_cost;      //This variable sets the cost of the card (all cards have cost)
             
             int m_value;     //this is the value of the card, if !=0 it means this is a treasure card
             int m_victory;   //this is the amount of victory points this card gives, if !=0 it means it is a victory card
            }

#endif
