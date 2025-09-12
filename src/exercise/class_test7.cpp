

class A{
    public:
        A(const A &) = delete;
        A(int a);
        A() = default;
}
