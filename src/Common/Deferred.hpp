#ifndef DEFERRED_4HO6ROV7
#define DEFERRED_4HO6ROV7

#include <functional>
#include "Common/IDeferred.hpp"

template<class Ret = void>
class Deferred : public IDeferred {
    std::function<Ret()> procedure;
public:
    template<class Fn, class... Args> 
    Deferred(Fn&& fn, Args&&... args) {
        this->procedure = std::bind<Ret>(fn, args...);
    }

    Deferred(const Deferred&& second) {
        this->procedure = second.procedure;
    }

    void call() {
        procedure();
    }
    virtual ~Deferred() {}
};

#endif /* end of include guard: DEFERRED_4HO6ROV7 */
