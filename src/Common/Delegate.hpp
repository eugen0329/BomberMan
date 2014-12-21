#ifndef _DELEGATE_HPP_
#define _DELEGATE_HPP_
#include <iostream>

class Delegate {
// {{{ inner classes------------------------------
private:
    struct NilClass {};
    
    class IArgList { 
    public: 
        virtual ~IArgList() {} 
    };
    
    template<class T1 = NilClass, class T2 = NilClass, class T3 = NilClass>
    class ArgList : public IArgList {
    public: 
        T1 arg1; 
        T2 arg2;
        T3 arg3;
    public:
        ArgList() 
        {}
        ArgList( T1 arg1 ) :
        arg1( arg1 ) 
        {}
        ArgList(T1 arg1, T2 arg2) :
        arg1(arg1), 
        arg2(arg2)
        {}
        ArgList(T1 arg1, T2 arg2, T3 arg3) :
        arg1(arg1), 
        arg2(arg2), 
        arg3(arg3)
        {}
    };
    
    class IContainer { 
    public: 
        virtual ~IContainer() {}
        virtual void call(IArgList *) = 0; 
        virtual void writeCopyPtr(IContainer *&) = 0; 
    };
    
    template<class T, class M> 
    class Container : public IContainer {
    public: 
        virtual void Call( IArgList* ) {}
        virtual ~Container() {} 
        virtual void writeCopyPtr(IContainer*&) {}
    };
    // void arglist specification
    template< class T >
    class Container< T, void (T::*)(void) > : public IContainer {
    private: 
        typedef void (T::*M)(void);
    
        T* bindedClass; 
        M bindedMethod;
    public: 
        Container(T* newClass, M newMethod) : 
        bindedClass(newClass), 
        bindedMethod(newMethod) 
        {}
        Container( Container& second) : 
        bindedClass(second.bindedClass), 
        bindedMethod(second.bindedMethod) 
        {}
        virtual ~Container()
        {}
        virtual void call(IArgList*)
        {
            (bindedClass->*bindedMethod)();
        }
        virtual void writeCopyPtr(IContainer*& destination) 
        {
            destination = new Container<T,M>(*this);
        }
    };

// one argument specification
    template<class T, class A1> 
    class Container< T, void (T::*)(A1) > : public IContainer {
    private: 
        typedef void (T::*M)(A1);
        typedef ArgList<A1> Args;
    
        T* bindedClass; 
        M  bindedMethod;
    public: 
        Container(T* newClass, M newMethod) : 
        bindedClass(newClass), 
        bindedMethod(newMethod) 
        {}
        Container(Container& second) : 
        bindedClass(second.bindedClass), 
        bindedMethod(second.bindedMethod) 
        {}
        virtual ~Container()
        {}
        virtual void call(IArgList* iArgs)
        {
            Args* args = static_cast<Args*>(iArgs);
            if(args) {
                (bindedClass->*bindedMethod)(args->arg1);
            }
        }
        virtual void writeCopyPtr(IContainer*& destination) 
        {
            destination = new Container<T,M>(*this);
        }
    };
    //two args specification
    template< class T, class A1, class A2 >
    class Container< T, void (T::*)(A1,A2) > : public IContainer {
    private: 
        typedef void (T::*M)(A1,A2);
        typedef ArgList<A1,A2> Args;
    
        T* bindedClass; 
        M bindedMethod;
    public: 
        Container(T* newClass, M newMethod) : 
        bindedClass(newClass), 
        bindedMethod(newMethod) 
        {}
        Container(Container& second) : 
        bindedClass(second.newClass), 
        bindedMethod(second.newMethod) 
        {}
        virtual ~Container()
        {}
        void call( IArgList* iArgs )
        {
            Args* args = static_cast<Args*>(iArgs);
            if(args) {
                (bindedClass->*bindedMethod)(args->arg1, args->arg2);
            }
        }
        virtual void writeCopyPtr(IContainer*& destination) 
        {
            destination = new Container<T,M>(*this);
        }
    };
    //three args specification
    template< class T, class A1, class A2, class A3>
    class Container< T, void (T::*)(A1,A2,A3) > : public IContainer {
    private: 
        typedef void (T::*M)(A1,A2,A3);
        typedef ArgList<A1,A2,A3> Args;
    
        T* bindedClass; 
        M bindedMethod;
    public: 
        Container(T* newClass, M newMethod) : 
        bindedClass(newClass), 
        bindedMethod(newMethod) 
        {}
        Container(Container& second) : 
        bindedClass(second.newClass), 
        bindedMethod(second.newMethod) 
        {}
        virtual ~Container()
        {}
        void call(IArgList* iArgs)
        {
            Args* args = static_cast<Args*>(iArgs);
            if(args) {
                (bindedClass->*bindedMethod)(args->arg1, args->arg2, args->arg3);
            }
        }
        virtual void writeCopyPtr(IContainer*& destination) 
        {
            destination = new Container<T,M>(*this);
        }
    };
// }}} ------------------------------
private:
    IContainer* container;
    bool isBinded_;
public:
    Delegate() : 
    container( NULL ) 
    {}
    explicit Delegate(const Delegate& sec)
    {
        if(sec.container) {
            sec.container->writeCopyPtr(this->container);
        }
        this->isBinded_ = sec.isBinded_;
    }
    virtual ~Delegate() 
    { 
        if(container) {
            delete container;
        } 
    }
    template<class T, class U> Delegate& bind(T* newClass, U newMethod) 
    {
        if(container) {
            delete container;
        }
        container = new Container<T, U>(newClass, newMethod);
        this->isBinded_ = true;
        return *this;
    }
    void operator() () {
        ArgList<> args;
        container->call(&args);
    }
    template<class T> 
    void operator() (T arg1) {
        ArgList<T> args(arg1);
        container->call(&args);
    }
    template<class T1, class T2> 
    void operator() (T1 arg1, T2 arg2) {
        ArgList<T1,T2> args(arg1, arg2);
        container->call(&args);
    }
    template<class T1, class T2, class T3> 
    void operator() (T1 arg1, T2 arg2, T3 arg3) {
        ArgList<T1,T2,T3> args(arg1, arg2, arg3);
        container->call(&args);
    }
    Delegate& operator = (const Delegate& second) 
    {
        if(this->container) {
            delete this->container;
        }
        if(second.container) {
            second.container->writeCopyPtr(this->container);
        } else {
            this->container = NULL;
        }
        this->isBinded_ = second.isBinded_;
        return *this;
    }
    bool isBinded()
    {
        return isBinded_;
    }
};

#endif /* end of include guard: _DELEGATE_HPP_ */
