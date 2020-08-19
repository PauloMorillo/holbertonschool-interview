#!/usr/bin/node
const request = require('request');

function requesito (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) reject(error);
      /* if (response.statusCode !== 200) {
        reject('Invalid status code <' + response.statusCode + '>');
      } */
      resolve(body);
    });
  });
}

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (error, response, body) {
  const characters = JSON.parse(body).characters;
  if (error !== null) {
    console.error(error);
  }
  let a = 0;
  while (a < characters.length) {
    try {
      const body = await requesito(characters[a]);
      console.log(JSON.parse(body).name);
    } catch (error) {
      console.error(error);
    }

    a = a + 1;
  }
});
