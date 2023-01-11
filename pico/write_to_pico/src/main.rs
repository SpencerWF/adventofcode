extern crate serial;

use std::fs;
use std::env;
use std::io;
use std::time::Duration;

// use std::io::prelude::*;
use serial::prelude::*;

fn main() {
    let data = read_input("../../input/2015/input5.txt".to_string());
    let converted_data = convert_input(data);
    let mut output_data: Vec<Vec<u8>> = [].to_vec();

    for line in converted_data {
        output_data.push(line.as_bytes().to_vec());
    }

    // let output_data = &converted_data.as_bytes();
    println!("{:?}", output_data[1]);

	let mut port = serial::open("/dev/ttyACM0").unwrap();
	interact(&mut port, output_data).unwrap();
}

fn convert_input(data: Vec<String>) -> Vec<String> {
    let mut buf: Vec<String> = [].to_vec(); //Change to Vec<u8> to get ready to send to pico
    for n in data {
        let mut converted_line: String = "".to_string();
        let mut test_string: String = "".to_string();
        // let line_chars = n.chars();
        if n.find('f')!=None {
            // n.replace_range(..8, "f");
            converted_line.push_str(&(format!("f{}",&n[9..]))[..]);
        } else if n.find('l')!=None {
            // n.replace_range(..6, "l");
            converted_line.push_str(&(format!("l{}",&n[7..]))[..]);
        } else {
            // n.replace_range(..7, "n");
            converted_line.push_str(&(format!("n{}",&n[8..]))[..]);
        }

        let th_start: usize = converted_line.find(" through ").unwrap();

        converted_line.replace_range(th_start..(th_start+9), &"-");

        buf.push(converted_line);
    }

    return buf;
}

fn interact<T: SerialPort>(port: &mut T, data: Vec<Vec<u8>>) -> io::Result<()> {
    port.reconfigure(&|settings| {
        settings.set_baud_rate(serial::Baud115200)?;
        settings.set_char_size(serial::Bits8);
        settings.set_parity(serial::ParityNone);
        settings.set_stop_bits(serial::Stop1);
        settings.set_flow_control(serial::FlowNone);
        Ok(())
    })?;

    port.set_timeout(Duration::from_millis(1000))?;

    // let mut buf: Vec<u8> = (0..255).collect();

    for line in data {
        port.write(&line)?;
    }
    // port.read(&mut buf[..])?;
    // let output: String = read_line(data);

    // println!("{:?}", output);

    Ok(())
}

fn read_input(filename: String) ->  Vec<String>{
    let data = fs::read_to_string(filename).expect("Unable to read file");
    // println!("{}", data.len());

    // Create an iterator to go through each line of the data from the input file
    let lines:Vec<String> = data.split('\n').map(str::to_string).collect();

    return lines;
}

fn read_line(mut input: Vec<u8>) -> String{
    let mut index = 0;
    let buf: Vec<u8>;

    input.retain(|x| *x < 128);
    for (i,c) in input.iter().enumerate() {
        if *c as char == '\r' {
            println!("Found Return Carriage at: {}", i);
            index = i;
            break;
        }
    }

    buf = input[0..index].to_vec();

    let output = String::from_utf8(buf).unwrap();

    return output;
}