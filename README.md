This is code for a C++ iostreams `num_put` facet to write numbers out using Roman numerals. For example, if we have `std::cout` use this facet:

```cpp
    auto loc = std::locale(std::locale(), new roman<char>);
    std::cout.imbue(loc);
```

We can then write out numbers something like this:

```
    for (int i = 1; i <= 100; i++) {
        std::cout << i << "\t";
        if (i % 10 == 0)
            std::cout << "\n";
    }
```

...and get output like this:

```
I	II	III	IV	V	VI	VII	VIII	IX	X	
XI	XII	XIII	XIV	XV	XVI	XVII	XVIII	XIX	XX	
XXI	XXII	XXIII	XXIV	XXV	XXVI	XXVII	XXVIII	XXIX	XXX	
XXXI	XXXII	XXXIII	XXXIV	XXXV	XXXVI	XXXVII	XXXVIII	XXXIX	XL	
XLI	XLII	XLIII	XLIV	XLV	XLVI	XLVII	XLVIII	XLIX	L	
LI	LII	LIII	LIV	LV	LVI	LVII	LVIII	LIX	LX	
LXI	LXII	LXIII	LXIV	LXV	LXVI	LXVII	LXVIII	LXIX	LXX	
LXXI	LXXII	LXXIII	LXXIV	LXXV	LXXVI	LXXVII	LXXVIII	LXXIX	LXXX	
LXXXI	LXXXII	LXXXIII	LXXXIV	LXXXV	LXXXVI	LXXXVII	LXXXVIII	LXXXIX	XC	
XCI	XCII	XCIII	XCIV	XCV	XCVI	XCVII	XCVIII	XCIX	C	
```

There probably aren't many circumstances under which this is really useful. It was mostly intended to show a semi-plausible
example of how to create and use a `num_put` facet within the iostreams framework.
