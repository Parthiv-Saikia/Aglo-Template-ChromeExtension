document.addEventListener("DOMContentLoaded", async () => {
    const search = document.getElementById("search");
    const results = document.getElementById("results");
    const code = document.getElementById("code");
    const copyBtn = document.getElementById("copyBtn");

    let templates = [];

    async function loadTemplates() {
        const res = await fetch('templates.json');
        templates = await res.json();
    }

    function displayResults(query) {
        results.innerHTML = ''; // clear all li items

        if (query.trim() === '') {
            results.style.display = 'none'; // hide results list
            return; // exit early
        }

        const filtered = templates.filter(t =>
            t.name.toLowerCase().includes(query.toLowerCase())
        );

        if (filtered.length === 0) {
            const li = document.createElement("li");
            li.textContent = "No results found";
            li.style.color = "#888";
            li.style.pointerEvents = "none";
            results.appendChild(li);
            results.style.display = 'block';
            return;
        }

        filtered.forEach(t => {
            const li = document.createElement("li");
            li.textContent = t.name;
            li.addEventListener("click", async () => {
                // Set the search bar to the clicked text
                search.value = t.name;

                // Load the corresponding code
                const res = await fetch(t.file);
                const text = await res.text();
                code.textContent = text;

                // Show code container only if text is not empty
                const codeContainer = document.getElementById("code-container");
                if (text.trim() !== '') {
                    codeContainer.style.display = 'block';
                } else {
                    codeContainer.style.display = 'none';
                }

                // Hide results after selection
                results.style.display = 'none';
            });

            results.appendChild(li);
        });


        results.style.display = 'block';
    }



    search.addEventListener("input", e => {
        const query = e.target.value.trim();

        displayResults(query);

        const codeContainer = document.getElementById("code-container");

        if (query === '') {
            code.textContent = '';
            codeContainer.style.display = 'none';
        } else {
            codeContainer.style.display = 'block';
        }
    });



    copyBtn.addEventListener("click", () => {
        navigator.clipboard.writeText(code.textContent).then(() => {
            copyBtn.classList.add("copy-animate");
            setTimeout(() => copyBtn.classList.remove("copy-animate"), 300);
        });
    });

    await loadTemplates();
    displayResults("");
});
