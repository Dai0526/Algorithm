class Foo {
    
public:
    typedef boost::function<void(const std::string&)> ErrorHandlerType;
    Foo(int n, const ErrorHandlerType& eh) { 
        id = n; 
        m_errHandler = eh;
    };
    void Create() {
        //Print();
        try {
            Print();
        }
        catch (ReconException& e) {
            cout<< e.ErrorMessage();
        }
    }

    void Print() {
        if (id == 4) {
            ThrowReconException("Error at ") << id;
        }
        cout << "id = " << id << " created\r\n";
    }

private:
    ErrorHandlerType m_errHandler;
    int id = 0;
};

int TestThreadPool() {
    boost::asio::thread_pool pool(8);

    try {
        for (int i = 0; i < 8; ++i) {
            Foo* agent = new Foo(i, boost::bind(&HandlerException, _1));
            boost::asio::post(pool, bind(&Foo::Create, boost::ref(*agent)));
        }

        pool.join();
    }
    catch (const ReconException& e) {
        cout << e.ErrorMessage();
    }catch(...) {
        cout << "Unhandled exception";
    }

    pool.join();

    return 0;
}
