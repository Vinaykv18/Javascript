
const a = new Promise((resolve, reject) => {
    setTimeout(() => {
      const r = Math.floor(Math.random()*10);

      if (r > 5) {
        resolve(`successful random: ${r}`);
      } else {
        reject(`error number is < 5: ${r}`);
      }
    }, 1000);
  });


a
  .then((userData) => {
    console.log(userData);
  })
  .catch((error) => {
    console.error('Error:', error);
  })
  .finally(() => {
    console.log('Fetch operation completed.');
  });
