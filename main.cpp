#include <iostream>


class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual class State* createState() = 0;
};


class ConcreteFactory : public AbstractFactory {
public:
    virtual class State* createState() override;
};


class State {
public:
    virtual ~State() {}
    virtual void handle() = 0;
};


class StartState : public State {
public:
    virtual void handle() override {
        std::cout << "StartState handling...\n";
    }
};


class EndState : public State {
public:
    virtual void handle() override {
        std::cout << "EndState handling...\n";
    }
};


class ConcreteStateFactory : public ConcreteFactory {
public:
    virtual class State* createState() override {
        return new StartState();
    }
};


class State* ConcreteFactory::createState() {
    return new StartState();
}


int main() {
    ConcreteFactory* factory = new ConcreteStateFactory();
    State* state = factory->createState();
    state->handle();

    delete state;
    delete factory;

    return 0;
}