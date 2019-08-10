#include "stdio.h"
#include "string.h"
#include "ctype.h"

typedef long int64_t;
typedef short int16_t;
typedef int int32_t;

void condition_1(unsigned char currentGuess) {
  const short int ** ctype_table = __ctype_b_loc();
  short int val = (*ctype_table)[(int)currentGuess];
  if(val & 256) {
    printf("%c\n",currentGuess);
  }
}

void condition_2(unsigned char currentGuess) {
  const short int ** ctype_table = __ctype_b_loc();
  short int val = (*ctype_table)[(int)currentGuess];
  if(val & 512) {
    printf("%c\n",currentGuess);
  }
}

void algo1(unsigned char currentGuess) {
  int64_t v7;
  const short int ** ctype_table = __ctype_b_loc();
  unsigned char v5 = currentGuess;  
  short int v6 = (*ctype_table)[(int)currentGuess];
  if ((v6 & 256) == 0) {
    const short int ** v8 = __ctype_b_loc(); // 0x124d
    //int64_t * v9 = (int64_t *)(a2 + 8); // 0x125d
    //unsigned char v10 = *(char *)(*v9 + v1); // 0x1266
    unsigned char v10 = currentGuess;
    //int16_t v11 = *(int16_t *)(2 * (int64_t)v10 + (int64_t)*v8); // 0x1273
    short int v11 = (*ctype_table)[(int)currentGuess];
    int64_t v12 = (int64_t)currentGuess;
    if ((v11 & 512) != 0) {
      int64_t v13 = v12 - 84; // 0x1299
      int32_t v14 = v13; // 0x12aa
      //v7 = v14 + 97 + -26 * ((int32_t)(0x4ec4ec4f * v13 / 0x100000000) / 8 - (v14 >> 31));
      v7 = (int64_t)(v14 + 97 + ((int32_t)(v13 * 0x4ec4ec4f / 0x100000000) / 8 - (v14 >> 31)) * -26);      
    } else {
      v7 = v12;
    }
    printf("%c %c\n",currentGuess,(unsigned char)v7);
  }
}

void algo2(unsigned char currentGuess) {
  const short int ** ctype_table = __ctype_b_loc();  
  short int condition = (*ctype_table)[(int)currentGuess];
  if((condition & 256)!= 0) {
    int64_t v15 = (int64_t)currentGuess - 52; // 0x1226
    int32_t v16 = v15; // 0x1237
    int64_t v17 = (int64_t)(v16 + 65 + ((int32_t)(v15 * 0x4ec4ec4f / 0x100000000) / 8 - (v16 >> 31)) * -26);    
    //unsigned char v17 = v16 + 65 + -26 * ((int32_t)(0x4ec4ec4f * v15 / 0x100000000) / 8 - (v16 >> 31)); // 0x1245
    printf("%c %c\n",(unsigned char)currentGuess,v17);
   }
}

void main(int argn, char** argv) {  
  /* printf("=================== BEGIN Condition 1 =====================\n"); */
  /* for(int charVal = 0; charVal <= 127; charVal++) { */
  /*   condition_1(charVal); */
  /* } */

  /* printf("=================== BEGIN Condition 2 =====================\n"); */
  /* for(int charVal = 0; charVal <= 127; charVal++) { */
  /*   condition_2(charVal); */
  /* } */

  printf("=================== BEGIN Algo 1 =====================\n");
  for(int charVal = 0; charVal <= 255; charVal++) {
    algo1(charVal);
  }
  printf("=================== END Algo 1 =====================\n");

  
  printf("=================== BEGIN Algo 2 =====================\n");
  for(int charVal = 0; charVal <= 255; charVal++) {
    algo2(charVal);
  }
  printf("=================== END Algo 2 =====================\n");
}
