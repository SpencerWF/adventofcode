const fs = require('fs');

filename = '../../input/2022/input1.txt'

const file = fs.readFileSync(filename, 'utf-8');

const lines = file.split('\n\n');

let elf_totals = [];

for (let index = 0; index < lines.length; index++) {
    // const element = lines[index];
    lines[index] = lines[index].split('\n');
    let total = 0;
    for (let num = 0; num < lines[index].length; num++) {
        // const element = lines[index][num];
        lines[index][num] = parseInt(lines[index][num]);
        total += lines[index][num];
    }
    elf_totals.push(total);
}

elf_totals.sort((a,b) => a-b);

// let most_calories = 0;
// for(let index = 0; index < elf_totals.length; index++) {
//     if(elf_totals[index] > most_calories) {
//         most_calories = elf_totals[index];
//     }
// }

// var nice_count = 0;

// lines.forEach(line => {
//     if(check_line(line)) {
//         console.log("")
//     }
// });
// console.log("estyydmzothggudf is nice: " + check_line('estyydmzothggudf'));
console.log(elf_totals[elf_totals.length-1] + elf_totals[elf_totals.length-2] + elf_totals[elf_totals.length-3]);