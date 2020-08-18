#!/usr/bin/node
const request = require('request');
request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (error, response, body) {
  const characters = JSON.parse(body).characters;
  if (error != null) {
    console.error(error);
  }
  let a = 0;
  while (a < characters.length) {
    request(characters[a], function (error, response, body) {
      if (error != null) {
        console.error(error);
      }

      console.log(JSON.parse(body).name);
    });
    a = a + 1;
  }
});
