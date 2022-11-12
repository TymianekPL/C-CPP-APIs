#[allow(dead_code, non_snake_case, non_camel_case_types)]
struct logger {
    info: String,
    warn: String,
    err: String
}

impl logger {
    pub fn new() -> Self {
        return logger {
            info: "[\x1B[1m\x1B[36mInfo\x1B[22m\x1B[0m]: ".to_string(),
            warn: "[\x1B[1m\x1B[33mWarn\x1B[22m\x1B[0m]: ".to_string(),
            err: "[\x1B[1m\x1B[31mError\x1B[22m\x1B[0m]: ".to_string()
        }
    }

    pub fn Info(&mut self, text: &str) {
        println!("{}{}", self.info, text);
    }

    pub fn Warn(&mut self, text: &str) {
        println!("{}{}", self.warn, text);
    }

    pub fn Error(&mut self, text: &str) {
        println!("{}{}", self.err, text);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
    	let mut a = logger::new();
    	a.Warn("You Aren't 18 Years Old! LOL");
    }
}
