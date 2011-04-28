#include "actioncard.h"

ActionCard::ActionCard(int cost, int actions, int value=0, int victory=0) 
                           : m_actions(actions), Card(cost, value, victory)
{
                         }

void ActionCard::action(){

     enum actionsEnumed {CARDS1 = 1, CARDS2 = 2, CARDS4 = 4,
                         ACTIONS1 = 8, ACTIONS2 = 16, ACTIONS4 = 32,
                         CREDITS1 = 64, CREDITS2 = 128, CREDITS4 = 256,
                         BUYS1 = 512, BUYS2 = 1024, BUYS4 = 2048};
     /*
       As I have enumed using the binary code it will be better to code using binary operators
       It's simpler to realize that the action 42 is 010101000(...)00 and therefore 3 actions
       (where there's 1).
       So, originally there was a conter witch counted only in 2^x, (that in binary are 1, 10, 100, 1000, etc)
       Therefore it verified action by action.
       But since we can group this actions in 4 groups of 3 actions each, so the first will be the last 3 bits (xxx)
       second the 6-3 bits (xxx000), and so forth.
       To make a bit by bit AND with a all 0 exept for those 3 bits, it will get me the amout in those 3 bits.
       Again with my example of a card with action 42 (01010100(...)0) we can separate it in 010 and 101, all the rest is 0
       therefore meaningless. So this 2 groups of 3 bits tells me that that card draws 3 (010) cards and gives 5 (101) actions.
       
       It may seem complex to follow with decimal numbers, think on them as binary, and it'all make sence.
       So, now the counter goes: 7, 56, 448, 3584 (111, 111|000, 111|000|000, 111|000|000|000) (the | is just foe separating the 3bit groups)
       this is exactly the same reasoning as above, exept it checks 3 bits at a time (the 3 actions of the same kind)
       However, it returns the number for that action, followed of unwanted 0.
       In the example before, the AND would have returned 010 for the first action and 101000 for the second, now I could makee a left shift.
       but I don't like the ideia, so I just dided by 8 (1|000 in binary) and for 64 (8*8 or 1|000|000 in binary) on the second and so on.
     */
                         
     for(int cont = 7; cont <= 3584; cont *= 8){
       int tmpActions = m_actions & cont;
       if (tmpActions != 0){
	 switch(cont){
	   case 7:
	     //Here things are easy, for 1-7 means exactly that
	     break;
	   case 56:
	     //however, here because of binary conversion I have to divide tmpActions by 8
	     break;
	   case 448:
	     //and here by 64
	     break;
	   case 3584:
	     //and here by 512
	     break;
	}
	 
	}
     }
