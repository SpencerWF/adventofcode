const fs = require('fs');

filename = '../../input/2015/input4.txt'

const vowels = [
    'a', 'e', 'i', 'o', 'u'
];

const bad_combos = [
    'ab', 'cd', 'pq', 'xy'
];

// function check_bad_combos(line) {
//     line.forEach(character => {})
// }

// function vowel_count(line) {
//     line.forEach(character => {

//     })
// }

function check_line(line) {
    var double_combo_check = false;
    var space_repeat_check = false;
    var current_combo = "";
    var new_combo = "";

    // Iterate through the line
    for(let index = 0; index < line.length; index++) {
        character = line[index];

        // If this criteria has already been passed on a line, no need to continue checking
        if(!double_combo_check) {
            if(index < line.length-1 ){
                current_combo = line[index] + line[index+1]
                
                // Make sure to avoid overlap
                for(let index2 = index+2; index2 < line.length-1; index2++) {
                    new_combo = line[index2] + line[index2+1];
                    if(line[index2] + line[index2+1] == current_combo) {
                        // console.log("Success: " + current_combo + " equals " + new_combo);
                        double_combo_check = true;
                    }
                }
            } else {
                // console.log(line + " does not pass double combo check before length runs out");
                return false;
            }
        }

        // If the first criteria has already been passed on a line, no need to continue checking
        if(!space_repeat_check) {
            if(index >= line.length - 2) {
                // Line does not pass space repeat check before it becomes impossible
                return false;
            } else {
                if(character == line[index+2]) {
                    space_repeat_check = true;
                }
            }
        }
        
        // If both criteria have already been passed end the loop
        if(double_combo_check && space_repeat_check){
            // console.log(line + " passes both checks");

            return true;
        }
    }
    return false;
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