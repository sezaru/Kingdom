#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include "card.h"

class ActionCard : Card{
      public:
             ActionCard(int cost, int actions, int value=0, int victory=0);
             
             void action();
             
      private:
              //first Idea: int m_actions;   //this is the action of the card, it will be enumed as to call the relative actions.       
              /*//Second Idea
              int m_draw;        //this is the value +(m_draw)cards
              int m_actions;     //this is the value +(m_actions)actions
              int m_credits;     //this is the value +(m_credits) coins
              int m_buys;        //this is the value +(m_buys) buys
              */
              
              int m_actions;            //here will be enumed just the basic actions, witch are listed below:
              /*
                a Reminder on how this will work:
                           m_actions will recive a value from the xml, let's say 42
                           this value is enumed somewhere (don't know where yet), to transform it
                           to 32+8+2 witch means this card has the actions 32, 8 AND 2.
                           
                           The enumed actions will be:
                               + cards (1, 2 & 4)
                               + actions (1, 2 & 4)
                               + credits (1, 2 & 4)
                               + buys (1, 2 & 4)
                           this allows to make any of this up to 7 (just call for the 3 actions)
                           witch should be good enought for any purpose
              */
   }

#endif
