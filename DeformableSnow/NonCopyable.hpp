#ifndef NON_COPYABLE_HPP
#define NON_COPYABLE_HPP

class NonCopyable {
public:
	NonCopyable(const NonCopyable& other) = delete;
	NonCopyable& operator=(const NonCopyable& other) = delete;
	NonCopyable() = default;
};

#endif //NON_COPYABLE_HPP