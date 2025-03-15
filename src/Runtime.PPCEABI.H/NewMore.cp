namespace std {
    class exception {
        public:
        exception() {};
        virtual ~exception();
        virtual const char *what() const;
    };
}

const char *std::exception::what() const {
    return "exception";
};

std::exception::~exception() {};
