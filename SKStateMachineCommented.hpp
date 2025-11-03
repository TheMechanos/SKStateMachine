#pragma once

#include "SKStateMachine.hpp"

#if defined(ARDUINO)

namespace SK{

template <typename E> class StateMachineCommented : public StateMachine<E> {
public:
    StateMachineCommented(E initial, String comment = "")
        : StateMachine<E>(initial)
        , comment(comment) { }

    inline String getComment() { return comment; }
    inline void setComment(String comment) { this->comment = comment; }


    operator String() { return comment; }

    StateMachineCommented& operator=(E value) {
        StateMachine<E>::setState(value);
        comment = "";
        return *this;
    }

    StateMachineCommented& operator=(String comment) {
        this->comment = comment;
        return *this;
    }

    void set(E state, String comment = "") {
        *this = state;
        *this = comment;
    }

private:
    String comment;
};

}

#endif