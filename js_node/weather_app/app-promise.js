const request = require('request');
const yargs = require('yargs');
const axios = require('axios');

const argv = yargs
    .options({
        a: {
            demand: true,
            alias: 'address',
            describe: 'address to fetch weather',
            string: true
        }
    })
    .help()
    .alias('help', 'h')
    .argv;
