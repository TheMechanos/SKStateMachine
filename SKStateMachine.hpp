#pragma once



#if defined(ARDUINO)
#include <Arduino.h>

#elif defined(ESP_PLATFORM)
#include <stdint.h>

#endif


namespace SK{

template <typename E> class StateMachine {
public:
    StateMachine(E initial)
        : act(initial)
        , last(initial) { }

    inline E getState() { return act; }
    inline void setState(E s) { act = s; }


    inline bool is(E s) { return act == s; }

    inline bool isChangeTo(E to) {
        if (act != last && act == to) {
            last = act;
            return true;
        }
        return false;
    }

    inline bool isChangeFromTo(E from, E to) {
        if (act != last && last == from && act == to) {
            last = act;
            return true;
        }
        return false;
    }

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
