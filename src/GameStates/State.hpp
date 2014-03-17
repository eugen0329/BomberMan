#ifndef _STATE_HPP_
#define _STATE_HPP_

class State {
private:
public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif /* end of include guard: _STATE_HPP_ */
