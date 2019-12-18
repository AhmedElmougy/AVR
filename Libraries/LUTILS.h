#ifndef __L_UTILS_H__
#define __L_UTILS_H__

#define  SET_BIT(REG,BIT)     REG|=(1<<BIT)
#define  CLEAR_BIT(REG,BIT)   REG&=~(1<<BIT)
#define  TOGGLE_BIT(REG,BIT)  REG^=(1<<BIT)
#define  GET_BIT(REG,BIT)     ((REG>>BIT)&1)
#define  SET_BIT_VALUE(REG,BIT,Value)   ({if (Value == 0){CLEAR_BIT(REG,BIT);} else{SET_BIT(REG,BIT);}})
#endif