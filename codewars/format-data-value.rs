/*

You get input data as a number (of megabytes). Your task is to convert it to the string adding 'MB' or 'GB' or 'TB' correctly.

Find the details below:

900 -> '900MB'
1900 -> '1GB 900MB'
568200 -> '568GB 200MB'
1000000 -> '1TB'
1234567 -> '1TB 234GB 567MB'

P.S. 0 <= input number < 1000000000

*/

fn main() {
    assert_eq!(format(0), "0MB");
    assert_eq!(format(900), "900MB");
    assert_eq!(format(1900), "1GB 900MB");
    assert_eq!(format(568200), "568GB 200MB");
    assert_eq!(format(1000000), "1TB");
    assert_eq!(format(1234567), "1TB 234GB 567MB");
}

fn format(mut size: usize) -> String {
    if size == 0 {
        return format!("0MB");
    }

    let units = ["TB", "GB", "MB"];
    let scales = [1000000, 1000, 1];
    let mut result = format!("");
    for i in 0..units.len() {
        let value = size / scales[i];
        if value > 0 {
            result = format!("{result}{}{} ", value, units[i]);
            size -= value * scales[i];
        }
    }
    format!("{}", result.trim())
}
