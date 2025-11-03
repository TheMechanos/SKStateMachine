#pragma once



#if defined(ARDUINO)
#include <Arduino.h>

#elif defined(ESP_PLATFORM)
#include <stdint.h>

#endif


namespace SK {

template <typename E> class StateMachine {
public:
    StateMachine(E initial)
        : act(initial)
        , last(initial) { }

    inline E getState() { return act; }
    inline void setState(E s) {
        sync();
        act = s;
    }


    inline bool is(E s) { return act == s; }

    inline bool isChange() { return act != last; }
    inline bool isChangeTo(E to) { return act != last && act == to; }
    inline bool isChangeFromTo(E from, E to) { return act != last && last == from && act == to; }
    

    inline void sync() { last = act; }


    operator E() { return act; }

    StateMachine& operator=(E value) {
        setState(value);
        return *this;
    }

private:
    E act;
    E last;
};


}
