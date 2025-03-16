
template <typename Alloc>
struct scoped_allocator_adaptor {
	Alloc alloc;

	template <typename T, typename... Args>
	void construct(T* ptr, const Args&... args) {
		if constexpr (std::uses_allocator<T, Alloc>) {
			using Inner = typename T::allocator_type;
			alloc.construct(ptr, args..., Inner(alloc));
		} else {
			alloc.construct(ptr, args...);
		}
	}

};
