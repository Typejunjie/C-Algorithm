const shall = require('child_process').exec;
const promptout = require('prompt');
const speedPath = 'https://github.do/https://github.com/Typejunjie/note-awesome.git';
const defaultPath = 'https://github.com/Typejunjie/note-awesome.git';

async function push() {
    await shall('git push', (err: Error, stdout: String, stderr: String) => {
        if (err) {
            console.log(stderr + 'default:' + count++);
            if(count > 20) {
                console.log('fatal to push');
                return
            }
            push();
        } else {
            console.log(stdout);
            /* shall(`git remote set-url origin '${JSON.stringify(defaultPath)}'`, (err: Error) => {
                if (!err) {
                    console.log("The path of push is reset");
                }
            }); */
            console.log("Commit into github is all success");
        }
    })
}
async function shallrun() {
    await shall('git add .', (err: Error, stdout: String, stderr: String) => {
        console.log(stdout, stderr);
    });
    await promptout.get('massage', (err: any, result: { massage: string }) => {
        if (err) {
            throw err;
        } else {
            shall(`git commit -m '${JSON.stringify(result.massage)}'`, (err: Error, stdout: String, stderr: String) => {
                if (err) {
                    console.log(stdout, stderr);
                } else {
                    console.log('add and commit was successfull');
                    promptout.get('push', (err: any, result: any) => {
                        if (err) {
                            throw err;
                        } else {
                            if (result.push == 'Y') {
                               /*  shall(`git remote set-url origin '${JSON.stringify(speedPath)}'`, (err: Error) => {
                                    if (!err) {
                                        
                                    }
                                }); */
                                push();
                            }
                        }
                    });
                }
            });
        }
    });
}
let count = 1;
shallrun();

export default void 0