function compressString() {
    const inputString = document.getElementById('inputString').value;
    let compressed = '';
    let count = 1;

    // Loop through the string and compress it
    for (let i = 0; i < inputString.length; i++) {
        if (inputString[i] === inputString[i + 1]) {
            count++;
        } else {
            compressed += inputString[i] + count;
            count = 1;
        }
    }

    // Display the result
    document.getElementById('result').innerText = "Compressed String: " + compressed;
}
