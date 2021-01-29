$(".login-form").submit(function (e) {
    e.preventDefault();
    const username = $("#username").val().trim();
    const email = $("#email").val().trim();
    const phone = $("#phone").val();
    const password = $("#password").val();
    const pass2 = $("#confirm-password").val();

    if (username === "" || email === "" || phone === "" || password === "") {
        alert("Empty fields not allowed");
    } else if (phone.toString().length != 10) {
        alert("Phone number must be 10 digits!");
    } else if (password !== pass2) {
        alert("Password must be same in both the fields!");
    } else if (password.length < 7) {
        alert("Password must be atleast 7 characters");
    } else if (email.lastIndexOf(".") - email.indexOf("@") <= 3) {
        alert("There should be atleast 3 spaces between the last . and @");
    } else if (
        email.length - 1 - email.lastIndexOf(".") != 3 &&
        email.length - 1 - email.lastIndexOf(".") != 2
    ) {
        alert("There must be 2 or 3 characters after the last .");
    } else {
        const allowed =
            "abcdefghijklmnopqrstuvwzyxABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890#$@&";
        const specialChar = "@#$&";
        let upper = (lower = special = false);

        for (let i = 0; i < password.length; i++) {
            const ch = password.charAt(i);
            const ascii = ch.charCodeAt(0);
            if (!allowed.includes(ch)) {
                alert("Invalid character in password!");
                break;
            } else if (ascii >= 65 && ascii <= 90) {
                upper = true;
            } else if (ascii >= 97 && ascii <= 122) {
                lower = true;
            } else if (specialChar.includes(ch)) {
                special = true;
            }
        }
        if (!lower || !upper || !special) {
            alert(
                "Password must contain atleast 1 special, lower and upper case character"
            );
        } else {
            alert("Account created!");
            this.submit();
        }
    }
});

$("#password-checkbox").click(function () {
    if ($(this).prop("checked") === true) {
        $("#password").attr("type", "text");
    } else {
        $("#password").attr("type", "password");
    }
});
