const fs = require('fs');

filename = '../../input/2015/input4.txt'

const vowels = [
    'a', 'e', 'i', 'o', 'u'
];

const bad_combos = [
    'ab', 'cd', 'pq', 'xy'
];

function check_line(line) {
    var vowel_cnt = 0;
    var double_check = false;
    var bad_check = false;
    var character = '';

    for(let index = 0; index < line.length; index++) {
        character = line[index];

        // Check if remaining length exists for criteria to be passed
        if(index < line.length - 1){
            if(bad_combos.indexOf(character + line[index+1])>=0) {
                // If this criteria fails, no need to continue loop
                bad_check = true;
                console.log(line + " is bad from combo");
                return false;
            }
            if(character==line[index+1]) {
                double_check = true;
            }
        }
        if(vowels.indexOf(character)>=0) {
            vowel_cnt++;
        }
    }

    if(vowel_cnt >= 3 && double_check && !bad_check){
        console.log(line + " is nice");
        return true;
    } else {
        console.log(line + " is naughty");
        return false;
    }
}

const file = fs.readFileSync(filename, 'utf-8');

const lines = file.split('\n');

var nice_count = 0;

lines.forEach(line => {
    if(check_line(line)) {
        nice_count++;
    }
});
// console.log("estyydmzothggudf is nice: " + check_line('estyydmzothggudf'));
console.log("Nice count is: " + nice_count);