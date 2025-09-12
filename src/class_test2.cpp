class B;

class A{
    protected:
        B *b = nullptr;
};

class B{
    protected:
        A *a = nullptr;
};
