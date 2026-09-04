#include "nivel1.h"
#include "sit1_1.h"
#include "sit1_2.h"
#include "sit1_3.h"
#include "sit1_4.h"
#include "sit1_5.h"

bool jugar_nivel1(){
    return sit1_1() && sit1_2() && sit1_3() && sit1_4() && sit1_5();
}