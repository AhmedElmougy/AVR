#ifndef __HLCD_Privte_h__
#define __HLCD_Privte_h__

#define HLCD_4BIT 0
#define HLCD_8BIT 1

//Configuration of LCD Instructions

#define Disp_CLEAR 0b00000001
/* *Display CLEAR instruction format
   *0b00000001
   *Clear Display and return cursor to initial position
   *Initialize Address counter AC 
   *Fill LCD DDRAM with spaces
*/
#define RET_HOME 0b00000010
/* *Return home instruction format
   *0b0000001-X
   *X:Don't care
   *return cursor to initial position
   *Doesn't effect DDRAM
*/
#define ENTRY_MODE 0b00000110
/* *Entry mode instruction format
   *0b000001-I/D-Sh
   *I/D:Cursor Direction 0->decrement/1->Increment
   *Sh:Cursor on  0->NO Shift/1->Shift R/L epend on I/D 
*/
#define Disp_ON_OFF 0b00001111
/* *Display ON OFF instruction format
   *0b00001-D-C-B
   *D:Display on 0->OFF/1->ON
   *C:Cursor on  0->OFF/1->ON
   *B:Blinking   0->OFF/1->ON
*/
#define Disp_OFF 0b00001011
/* *Display ON OFF instruction format
   *0b00001-D-C-B
   *D:Display on 0->OFF/1->ON
   *C:Cursor on  0->OFF/1->ON
   *B:Blinking   0->OFF/1->ON
*/
#define CURSOR_OFF 0b00001100
/* *Display ON OFF instruction format
   *0b00001-D-C-B
   *D:Display on 0->OFF/1->ON
   *C:Cursor on  0->OFF/1->ON
   *B:Blinking   0->OFF/1->ON
*/
#define BLINK_OFF 0b00001110
/* *Display ON OFF instruction format
   *0b00001-D-C-B
   *D:Display on 0->OFF/1->ON
   *C:Cursor on  0->OFF/1->ON
   *B:Blinking   0->OFF/1->ON
*/
#define DISP_SHIFT_RIGHT 0b00011100
/* *Shift Right display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define DISP_SHIFT_LEFT 0b00011000
/* *Shift Left display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define CURSOR_SHIFT_RIGHT 0b00010100
/* *Shift Right display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define CURSOR_SHIFT_LEFT 0b00010000
/* *Shift Left display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define WHOLE_SCRN_SHIFT_RIGHT 0b00011100
/* *Shift Right display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define WHOLE_SCRN_SHIFT_LEFT 0b00011000
/* *Shift Left display instruction format
   *0b0001-S/C-R/L-X-X
   *R/L:Cursor Direction 0->Shift Left/ 1->Shift Right
   *S/C:Shift on  0->no shift /1->Shift Shift entire disp with cursor Right or Left depend on S/C 
*/
#define FN_SET 0b00111100
/* *Functions set instruction format
   *0b001-DL-N-F-X-X
   *DL:Data length    0->4BIT/1->8BIT
   *N:Number of lines 0->(1)/1->(2)
   *F:Character Font  0->(5X7)/1->(5X10)
*/
#define DDRAM_ADD1 0b10000000
/* *set DDRAM address instruction format
   *0b1-AC6~AC0
   *AC: address counter bits from 0 to 6
*/
#define DDRAM_ADD2 0b11000000
/* *set DDRAM address instruction format
   *0b1-AC6~AC0
   *AC: address counter bits from 0 to 6
*/

#define FN_SET_4BIT1 0b00100010
/* *Functions set instruction format
   *send 0010 two times i a row
*/

#define FN_SET_4BIT2 0b11000000
/* *Functions set instruction format
   *N-F-X-X
   *N:Number of lines 0->(1)/1->(2)
   *F:Character Font  0->(5X7)/1->(5X10)
*/


#endif
