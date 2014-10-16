
fn test_string(){
	//string is a sequence of unicode scalar values encoded as a stream of utf-8 bytes

	// &str string slice, have a fixed size, and cannot be mutated
	let s1 = "hello world";
	println!("{}",s1);

	// String is an in-memory string, is growable
	let mut s2 = "hello world".to_string();
	s2.push_str(" xhma");
	println!("{}", s2);

	// is cheap than &str convert to String
	let s3 = s2.as_slice();
	// s3.push_str("test"); error
	println!("{}", s3);

	let s4 = s1.to_string();
	// if want update, must declare mut
	// s4.push_str("ff");
	println!("{}", s4)

}


fn test_array(){
	// Vector
	let v = vec![1i];
	println!("{}", v);
}

fn test_literal(){
	//string_literal
	println!("{} {} {}", "string_literal", r"\naaa", r#"dd"#);
	//char literal
	println!("{} {} {} {}", 'a', '\n', '\u1234', 'c');
	//byte , byte string literal
	println!("{} {}", b"R", b"foo");
	// Number litral);
	// 1i, 1u, 1i32, 1u32
	println

}
fn main(){
	test_string();

	test_array();

	test_literal();
}