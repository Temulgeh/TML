#ifndef TML_INCLUDE_ARRAY
#define TML_INCLUDE_ARRAY

    #include <vector>
    #include <ranges>
    #include <type_traits>


    namespace TML
    {
        template <typename ValueType>
        class Array
        {
        public:
            using Iterator = std::vector<ValueType>::iterator;

            Array();
            template <std::ranges::range Values> requires
                std::is_convertible_v<std::ranges::range_value_t<Values>, ValueType>
            Array(const Values & data);
            template <std::ranges::range Values, std::ranges::range Sizes> requires
                std::is_convertible_v<std::ranges::range_value_t<Values>, ValueType>
             && std::is_convertible_v<std::ranges::range_value_t<Sizes>, size_t>
            Array(const Values & data, const Sizes & shape);

            Iterator begin();
            Iterator end();
            const Iterator begin() const;
            const Iterator end() const;
            const Iterator cbegin() const;
            const Iterator cend() const;

            ValueType & operator [](size_t index);
            const ValueType & operator [](size_t index) const;

        private:
            std::vector<ValueType> data;
            std::vector<size_t> shape;
        };
    }

#endif
