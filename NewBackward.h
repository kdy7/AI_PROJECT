#ifndef NEWBACKWARD_H
#define NEWBACKWARD_H

#include "NewBackward.h"

class NewBackward{
public:
    void run_backward();
    NewBackward();
private:
    void init(void);
    void determine_member_concl_list(void);
    void push_on_stack(void);
    void instantiate(void);
    void ifSwitch();
    void thenSwitch(void);
    void recursive_search(void);
};

#endif
