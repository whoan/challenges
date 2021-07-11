https://leetcode.com/problems/integer-to-roman/

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let mut result = String::new();
        let mut roman_letters: &[char] = &['Z', 'Y', 'M', 'D', 'C', 'L', 'X', 'V', 'I'];
        let mut divisor = 1000;

        const Tens: usize = 0;
        const Fives: usize = 1;
        const Units: usize = 2;

        while num > 0 {
            result.push_str(&match num / divisor {
                n @ 0..=3 => format!("{}",   roman_letters[Units]).repeat(n as usize),
                4         => format!("{}{}", roman_letters[Units], roman_letters[Fives]),
                n @ 5..=8 => format!("{}{}", roman_letters[Fives], format!("{}", roman_letters[Units]).repeat((n%5) as usize)),
                9         => format!("{}{}", roman_letters[Units], roman_letters[Tens]),
                _ => panic!("not possible")
            });
            num %= divisor;
            divisor /= 10;
            roman_letters = &roman_letters[2..];
        }
        result
    }
}

impl LessHeapSolution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let mut result = String::new();
        let mut roman_letters: &[char] = &['Z', 'Y', 'M', 'D', 'C', 'L', 'X', 'V', 'I'];
        let mut divisor = 1000;

        const Tens: usize = 0;
        const Fives: usize = 1;
        const Units: usize = 2;

        while num > 0 {
            match num / divisor {
                n @ 0..=3 => {
                    for _ in 0..n { result.push(roman_letters[Units]); }
                },
                4 => {
                    result.push(roman_letters[Units]);
                    result.push(roman_letters[Fives]);
                },
                n @ 5..=8 => {
                    result.push(roman_letters[Fives]);
                    for _ in 0..(n%5) { result.push(roman_letters[Units]); }
                },
                9 => {
                    result.push(roman_letters[Units]);
                    result.push(roman_letters[Tens]);
                },
                _ => panic!("not possible")
            }
            num %= divisor;
            divisor /= 10;
            roman_letters = &roman_letters[2..];
        }
        result
    }
}

impl AlternativeSolution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let mut result = String::new();
        let mut roman_letters = "ZYMDCLXVI";
        let mut divisor = 1000;

        const Tens: usize = 0;
        const Fives: usize = 1;
        const Units: usize = 2;

        while num > 0 {
            match num / divisor {
                n @ 0..=3 => {
                    for _ in 0..n { result.push(Self::get(roman_letters, Units)); }
                },
                4 => {
                    result.push(Self::get(roman_letters, Units));
                    result.push(Self::get(roman_letters, Fives));
                },
                n @ 5..=8 => {
                    result.push(Self::get(roman_letters, Fives));
                    for _ in 0..(n%5) { result.push(Self::get(roman_letters, Units)); }
                },
                9 => {
                    result.push(Self::get(roman_letters, Units));
                    result.push(Self::get(roman_letters, Tens));
                },
                _ => panic!("not possible")
            }
            num %= divisor;
            divisor /= 10;
            roman_letters = &roman_letters[2..];
        }
        result
    }

    fn get(roman_letters: &str, n: usize) -> char {
        roman_letters.chars().nth(n).unwrap()
    }
}
